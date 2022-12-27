package java_Week5;

import java.util.*;
import java.util.Random;

public class DotComGame {
    
	private GameHelper helper = new GameHelper();
    private ArrayList<DotCom> dotComsList = new ArrayList<DotCom>();
    private int numOfGuesses = 0; //��ǥ�Է�Ƚ��
    Random random = new Random();
    int rand = random.nextInt(3) + 3; //3~5���� �ϳ� �������� ������ ���� #���2
    
    private void setUpGame() {
    	//���� 5�� �����ϰ� ���� �̸� �ο�
        DotCom one = new DotCom();
        one.setName("First.com");
        DotCom two = new DotCom();
        two.setName("Second.com");
        DotCom three = new DotCom();
        three.setName("Third.com");
        DotCom four = new DotCom();
        four.setName("Forth.com");
        DotCom five = new DotCom();
        five.setName("Fifth.com");
        
        //rand������ �°� domComsList�� �߰�
        if(rand == 3) {
        	dotComsList.add(one);
            dotComsList.add(two);
            dotComsList.add(three);
        }
        if(rand == 4) {
        	dotComsList.add(one);
            dotComsList.add(two);
            dotComsList.add(three);
            dotComsList.add(four);
        }
        if(rand == 5) {
        	dotComsList.add(one);
            dotComsList.add(two);
            dotComsList.add(three);
            dotComsList.add(four);
            dotComsList.add(five);
        }
        
        System.out.println("���� ��������� ����");
        System.out.println("��ǥ �Է� Ƚ���� 50~70���� �����մϴ�");
        
        for(DotCom dotComToSet : dotComsList) { //rand���� ��ŭ�� ���Ŀ� ���� �ݺ�
            ArrayList<String> newLocation = helper.placeDotCom(4); //������ �м�
            
            dotComToSet.setLocationCells(newLocation);
        }
    }
    
    private void startPlaying() {
        
        while(!dotComsList.isEmpty()) { //���� ����� �������������
            
            String userGuess = helper.getUserInput("Enter a guess"); //������� �Է� ����
            checkUserGuess(userGuess);
            
            if(numOfGuesses > 70) { //��ǥ�Է°����� �Ѿ�����(#���5)
            	System.out.println("��ǥ �Է� Ƚ���� �Ѿ����ϴ�");
            	break;
            }
        }
        if(numOfGuesses <= 70) {//��ǥ�Է°����� �������� ������ �� ��������
        	System.out.println("��� ������ �� ����������ϴ�");
        	System.out.println("������ ������ ����" + rand); //���İ��� ���(#����߰�)
        }
        
    }
    
    private void checkUserGuess(String userGuess) {
        numOfGuesses++; //����Ƚ�� ����
        
        String result = "miss";
        
        for(DotCom dotComToTest : dotComsList) { //��� ���� ��ü�� ���� �ݺ�
            result = dotComToTest.checkYourself(userGuess);
           
            if(result.equals("hit")) {
                break;
            }
            if(result.equals("kill")) {
                
                dotComsList.remove(dotComToTest); //������� ������ ���ĸ�Ͽ��� ����
                break;
            }
        }
        System.out.println(result); //���ȭ�����(#���6)
        System.out.println("��ǥ�Է�Ƚ�� : " + numOfGuesses); //��ǥ�Է�Ƚ�� ���(#����߰�)
    }
    
    public static void main(String[] args) {
        DotComGame game = new DotComGame();
        game.setUpGame(); //���� �����ϱ�
        game.startPlaying(); //�Է��� ��ġ�� ������ �´��� Ȯ���ϰ� ������
    }
}