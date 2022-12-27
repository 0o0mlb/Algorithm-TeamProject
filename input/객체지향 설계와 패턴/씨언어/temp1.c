#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ��ü���� ����� ���� �����

public class Calculator {

    public int calculate(boolean firstGuest, List<Item> items) {
        int sum = 0;
        for (Item item : items) {
            if (firstGuest)
                sum += (int)(item.getPrice() * 0.9); // ù �մ� 10% ����
            else if (!item.isFresh())
                sum += (int)(item.getPrice() * 0.8); // �� �ż��� �� 20% ����
            else
                sum += item.getPrice();
        }
        return sum;
    }
}