#!/usr/bin/env python3
# -*- coding: utf-8 -*-


"""
���� ������ ������ ���¼� ���̿� ������ �����ϰ� ������� �н� ���۽��� ����
__author__ = 'Jamie (jamie.lim@kakaocorp.com)'
__copyright__ = 'Copyright (C) 2019-, Kakao Corp. All rights reserved.'
"""


###########
# imports #
###########
from argparse import ArgumentParser, Namespace
from collections import defaultdict
import logging
import os
import random
import sys
from typing import Iterator, List

from khaiii.munjong.sejong_corpus import Sentence, sents, Word
from khaiii.resource.char_align import Aligner, AlignError, MrpChr


#############
# variables #
#############
_MAP_DIC = defaultdict(list)    # char/tag => morpheme result mapping dictionary
_MAP_CASE = defaultdict(list)    # char/tag => case(word) dictionary


#############
# functions #
#############
def _print_restore_dic(args: Namespace):
    """
    �������� ������ ����Ѵ�.
    Args:
        args:  program arguments
    """
    if not args.restore_dic:
        return
    with open(args.restore_dic, 'w', encoding='UTF-8') as fout:
        with open('{}.case'.format(args.restore_dic), 'w', encoding='UTF-8') as fcase:
            for (char, tag), vals in _MAP_DIC.items():
                for idx, val in enumerate(vals):
                    print('{}/{}:{}\t{}'.format(char, tag, idx, MrpChr.to_str(val)), file=fout)
                    word = _MAP_CASE[char, tag][idx]
                    print('{}/{}:{}\t{}'.format(char, tag, idx, word), file=fcase)


def sent_iter(args: Namespace) -> Iterator[Sentence]:
    """
    sentence generator
    Args:
        args:  program arguments
    Yields:
        sentence
    """
    for name in sorted(os.listdir(args.corpus_dir)):
        if not name.endswith('.txt'):
            continue
        logging.info(name)
        path = '{}/{}'.format(args.corpus_dir, name)
        for sent in sents(open(path, 'r', encoding='UTF-8')):
            yield sent


def _maps_to_tag(word: Word, maps: List[List[MrpChr]]) -> List[str]:
    """
    ���� ������ �̿��� ���� �� �� ���� ���� ��� �±׸� �����Ѵ�.
    Args:
        word:  Word object
        maps:  ���� �� ���� ����
    Returns:
        ��� �±� ����Ʈ
    """
    tags = []
    for char, align in zip(word.raw, maps):
        if len(align) == 1 and align[0].char == char:
            tags.append(align[0].tag)
            continue
        tag = ':'.join([_.tag for _ in align])
        if (char, tag) in _MAP_DIC:
            vals = _MAP_DIC[char, tag]
            try:
                idx = vals.index(align)
            except ValueError:
                idx = len(vals)
                vals.append(align)
                _MAP_CASE[char, tag].append(word)
            tag = '{}:{}'.format(tag, idx)
        else:
            _MAP_DIC[char, tag].append(align)
            _MAP_CASE[char, tag].append(word)
            tag = '{}:0'.format(tag)
        tags.append(tag)
    return tags


def _print_sent(sent: Sentence, word_per_maps: List[List[List[MrpChr]]]):
    """
    �� ���� �� ���� ���� ����Ʈ�� �̿��� �� ������ ����Ѵ�.
    Args:
        sent:  Sentence object
        word_per_maps:  �� �������� ���� ���� ������ �����ϴ� ����Ʈ
    """
    lines = []
    has_error = False
    for word, maps in zip(sent.words, word_per_maps):
        if maps:
            if len(word.raw) == len(maps):
                lines.append('{}\t{}'.format(word.raw, ' '.join(_maps_to_tag(word, maps))))
            else:
                raise RuntimeError('length of maps is different from length of word')
        else:
            has_error = True
            logging.debug(word)
    if not has_error:
        print('\n'.join(lines))
        print()


def run(args: Namespace):
    """
    run function which is the start point of program
    Args:
        args:  program arguments
    """
    aligner = Aligner(args.rsc_src)
    funmap = open(args.unmapped, 'w', encoding='UTF-8') if args.unmapped else None

    for sent in sent_iter(args):
        if 0.0 < args.sample < 1.0 and random.random() >= args.sample:
            continue
        word_per_maps = []
        for word in sent.words:
            try:
                maps = aligner.align(word)
            except AlignError as algn_err:
                if funmap:
                    algn_err.add_msg(str(word))
                    print(algn_err, file=funmap)
                maps = []
            word_per_maps.append(maps)
        _print_sent(sent, word_per_maps)

    _print_restore_dic(args)
    aligner.print_middle_cnt()

#���̽�

########
# main #
########
def main():
    """
    main function processes only argument parsing
    """
    parser = ArgumentParser(description='���� ������ ��ü���� ����� ����  ������ ���¼� ���̿� ������ �����ϰ�'
                                        ' ������� �н� ���۽��� ����')
    parser.add_argument('-c', '--corpus-dir', help='corpus dir', metavar='DIR', required=True)
    parser.add_argument('--rsc-src', help='resource source dir <default: ../rsc/src>',
                        metavar='DIR', default='../rsc/src')
    parser.add_argument('--output', help='output file <default: stdout>', metavar='FILE')
    parser.add_argument('--restore-dic', help='restore dic output file', metavar='FILE')
    parser.add_argument('--unmapped', help='unmapped log file', metavar='FILE')
    parser.add_argument('--sample', help='sampling ratio', metavar='REAL', type=float, default=1.0)
    parser.add_argument('--debug', help='enable debug', action='store_true')
    args = parser.parse_args()

    if args.output:
        sys.stdout = open(args.output, 'w', encoding='UTF-8')
    if args.debug:
        logging.basicConfig(level=logging.DEBUG)
    else:
        logging.basicConfig(level=logging.INFO)

    run(args)


if __name__ == '__main__':
    main()