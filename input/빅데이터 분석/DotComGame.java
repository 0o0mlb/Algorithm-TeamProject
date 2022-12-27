package java_Week5;

import java.util.*;
import java.util.Random;

public class DotComGame {
    
	private GameHelper helper = new GameHelper();
    private ArrayList<DotCom> dotComsList = new ArrayList<DotCom>();
    private int numOfGuesses = 0; //좌표입력횟수
    Random random = new Random();
    int rand = random.nextInt(3) + 3; //3~5수중 하나 랜덤으로 변수에 저장 #기능2
    
    private void setUpGame() {
    	//닷컴 5개 생성하고 각각 이름 부여
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
        
        //rand개수에 맞게 domComsList에 추가
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
        
        System.out.println("닷컴 가라앉히기 게임");
        System.out.println("좌표 입력 횟수를 50~70으로 제한합니다");
        
        for(DotCom dotComToSet : dotComsList) { //rand개수 만큼의 닷컴에 대해 반복
            ArrayList<String> newLocation = helper.placeDotCom(4); //빅데이터 분석
            
            dotComToSet.setLocationCells(newLocation);
        }
    }
    
    private void startPlaying() {
        
        while(!dotComsList.isEmpty()) { //닷컴 목록이 비어있지않으면
            
            String userGuess = helper.getUserInput("Enter a guess"); //사용자의 입력 받음
            checkUserGuess(userGuess);
            
            if(numOfGuesses > 70) { //좌표입력개수가 넘었을때(#기능5)
            	System.out.println("좌표 입력 횟수가 넘었습니다");
            	break;
            }
        }
        if(numOfGuesses <= 70) {//좌표입력개수가 차기전에 닷컴을 다 맞췄을때
        	System.out.println("모든 닷컴을 다 가라앉혔습니다");
        	System.out.println("생성된 닷컴의 개수" + rand); //닷컴개수 출력(#기능추가)
        }
        
    }
    
    private void checkUserGuess(String userGuess) {
        numOfGuesses++; //추측횟수 증가
        
        String result = "miss";
        
        for(DotCom dotComToTest : dotComsList) { //모든 닷컴 객체에 대해 반복
            result = dotComToTest.checkYourself(userGuess);
           
            if(result.equals("hit")) {
                break;
            }
            if(result.equals("kill")) {
                
                dotComsList.remove(dotComToTest); //가라앉힌 닷컴을 닷컴목록에서 지움
                break;
            }
        }
        System.out.println(result); //결과화면출력(#기능6)
        System.out.println("좌표입력횟수 : " + numOfGuesses); //좌표입력횟수 출력(#기능추가)
    }
    
    public static void main(String[] args) {
        DotComGame game = new DotComGame();
        game.setUpGame(); //닷컴 설정하기
        game.startPlaying(); //입력한 위치와 닷컴이 맞는지 확인하고 결과출력
    }
}