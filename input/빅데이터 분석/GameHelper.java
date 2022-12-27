package java_Week5;

import java.io.*;
import java.util.*;
 
public class GameHelper {
    
    private static final String alphabet = "abcdefghij"; //��ġ ���� ����
    private int gridLength = 10;
    private int gridSize = 100; //map size 10*10(#���1)
    private int[] grid = new int[gridSize]; //��ġ ���� �迭
    private int comCount = 0; //���� �Է� ���� ī��Ʈ
    
    public String getUserInput(String prompt) { //����ڰ� ����࿡ �Է��� �޾ƿ�
        String inputLine = null;
        System.out.print(prompt + " ");
        try {
            BufferedReader is = new BufferedReader(new InputStreamReader(System.in));
            inputLine = is.readLine();//�Է¹������� ���ٴ����� �о string���� ��ȯ�� ���� inputLine�� ����
            if(inputLine.length() == 0 ) return null;
        } catch (IOException e) { //���ܰ� �߻�������
            System.out.println("OException: " + e);
        }
        return inputLine.toLowerCase();
    }
    
    public ArrayList<String> placeDotCom(int comSize) { //���� ��ġ�ڵ�����
        ArrayList<String> alphaCells = new ArrayList<String>();
        String temp = null; //������ ������ ���ڿ��� �ٲ��� ����
        int[] coords = new int[comSize]; //���� ��ġ���� �迭
        boolean success = false; //��ġ �����Ҷ� ���� �οﺯ��
        int location = 0; //������ ��ġ�� �������� ������ ����
        
        comCount++; //n��° ����
        int incr = 1;
        if((comCount % 2) == 1) { //���簢��������� ��ġ(�������� ��ġ #���3 �׸�size����)
            incr = gridLength;
        }
        
        while(!success) {
            location = (int)(Math.random() * gridSize); //�������� ���� ��ġ ����
            int x = 0; //��ġ��ų ������ n��° ��ġ
            success = true;
            while(success && x < comSize) { //���� �ڸ��� ������� Ȯ��(������ ��ġ�� �ʰ��� #���4)
                if(grid[location] == 0 ) {
                	coords[x++] = location; //���� ��ġ �迭�� location����
                    location += incr; //����ĭ Ȯ��
                    if(location >= gridSize) { //��踦 ��� ���
                        success = false; //��ġ �缳��
                    }
                    if(x>0 & (location % gridLength == 0)) {//10�� ����̰ų� �̹� ������ �ִ� �ڸ��϶�
                        success = false; //��ġ �缳��
                    }
                } else {
                    success = false;
                }
            }
        }
        
        int x = 0; //������ �м�
        int row = 0;
        int column = 0;
        while(x < comSize) { //4�� �ݺ�
            grid[coords[x]] = 1; //������� ��ǥ�� ����
            row = (int)(coords[x] / gridLength); //��(����)���� ����
            column = coords[x] % gridLength; //��(����)���� ����
            temp = String.valueOf(alphabet.charAt(column)); //������ ������ ���ĺ����� ��ȯ
            alphaCells.add(temp.concat(Integer.toString(row))); //temp�� ���ĺ��迭�� �߰�
            x++;
        }
        return alphaCells;
    }
}