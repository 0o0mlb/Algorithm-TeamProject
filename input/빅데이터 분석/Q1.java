package 빅데이터분석14;

import javax.swing.*;
import java.awt.event.*;

public class Q1 {

	public void go() {
		
		JFrame f = new JFrame();
		JPanel jp = new JPanel();
		JPanel jp1 = new JPanel();
		JPanel jp2 = new JPanel();
		JPanel jp3 = new JPanel();
		JPanel jp4 = new JPanel();
		JPanel jp5 = new JPanel();
		JPanel jp6 = new JPanel();
		
		JLabel l1 = new JLabel("1번"); l1.setBounds(20,20,80,30);
		JLabel l2 = new JLabel("2번"); l2.setBounds(20,20,80,30);
		JTextField text1 = new JTextField("1번버튼안눌림"); text1.setBounds(100,20,100,30);
		JTextField text2 = new JTextField("2번버튼안눌림"); text2.setBounds(100,20,100,30);
		JButton b1 = new JButton("1번버튼");
		b1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				text1.setText("1번눌림");
			}
		});
		JButton b2 = new JButton("2번버튼");
		b2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				text2.setText("2번눌림");
			}
		});
		JRadioButton rd1 = new JRadioButton("Radio Button1",true);
		JRadioButton rd2 = new JRadioButton("Radio Button2");
		JCheckBox cb1 = new JCheckBox("New Check box1",true);
		JCheckBox cb2 = new JCheckBox("New Check box2");
		JTextArea ta = new JTextArea("this is JTextArea", 5,15);
		JComboBox cb = new JComboBox(); cb.addItem("Apple");
		
		jp1.add(l1); jp1.add(text1);
		jp2.add(l2); jp2.add(text2);
		jp3.add(b1); jp3.add(b2);
		jp4.add(rd1); jp4.add(cb1);
		jp5.add(rd2); jp5.add(cb2);
		jp6.add(ta); jp6.add(cb);
		jp.add(jp1);
		jp.add(jp2);
		jp.add(jp3);
		jp.add(jp4);
		jp.add(jp5);
		jp.add(jp6);
		
		f.getContentPane().add(jp);
		
		f.setSize(600,300);
		f.setVisible(true);
	}
	
	public static void main(String[] args) {
		Q1 gui = new Q1();
		gui.go();
	}
}
