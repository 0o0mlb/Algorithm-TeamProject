package java_Week5;

import java.util.*;

public class DotCom {
    private ArrayList<String> locationCells; //�� ��ġ�� �������
    private String name;
    
    public void setLocationCells(ArrayList loc) {
        locationCells = loc;
    }
    
    public void setName(String n) { //������ �м�
        name = n;
    }
    
    public String checkYourself(String userInput) {
        String status = "miss";
        int index = locationCells.indexOf(userInput); //������ ��ġ�� index�� ����
        
        if(index >= 0) {
            locationCells.remove(index); //������ ��ġ ����
            if(locationCells.isEmpty()) { //��� ��ġ�� ������� Ȯ��
                status = "kill"; //������ ��ġ�� 4ĭ�� 1,2,3ĭ�� �¾�����
                System.out.println(name + "�� ����������ϴ�");
            } else {
                status = "hit"; //������ ��ġ�� 4ĭ ��� �¾�����
            }
        }
        return status; //kill, hit, miss�� �ϳ��� ���¸� ����
    }
}