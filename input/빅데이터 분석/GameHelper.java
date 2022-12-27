package java_Week5;

import java.io.*;
import java.util.*;
 
public class GameHelper {
    
    private static final String alphabet = "abcdefghij"; //위치 지정 변수
    private int gridLength = 10;
    private int gridSize = 100; //map size 10*10(#기능1)
    private int[] grid = new int[gridSize]; //위치 저장 배열
    private int comCount = 0; //닷컴 입력 순서 카운트
    
    public String getUserInput(String prompt) { //사용자가 명령행에 입력을 받아옴
        String inputLine = null;
        System.out.print(prompt + " ");
        try {
            BufferedReader is = new BufferedReader(new InputStreamReader(System.in));
            inputLine = is.readLine();//입력받은값을 한줄단위로 읽어서 string으로 반환한 값을 inputLine에 저장
            if(inputLine.length() == 0 ) return null;
        } catch (IOException e) { //예외가 발생했을때
            System.out.println("OException: " + e);
        }
        return inputLine.toLowerCase();
    }
    
    public ArrayList<String> placeDotCom(int comSize) { //닷컴 위치자동설정
        ArrayList<String> alphaCells = new ArrayList<String>();
        String temp = null; //숫자의 열값을 문자열로 바꿔줄 변수
        int[] coords = new int[comSize]; //실제 위치저장 배열
        boolean success = false; //위치 설정할때 쓰는 부울변수
        int location = 0; //닷컴의 위치를 랜덤으로 설정할 변수
        
        comCount++; //n번째 닷컴
        int incr = 1;
        if((comCount % 2) == 1) { //직사각형모양으로 배치(수직으로 배치 #기능3 네모size변경)
            incr = gridLength;
        }
        
        while(!success) {
            location = (int)(Math.random() * gridSize); //랜덤으로 닷컴 위치 설정
            int x = 0; //위치시킬 닷컴의 n번째 위치
            success = true;
            while(success && x < comSize) { //닷컴 자리가 비었는지 확인(닷컴이 겹치지 않게함 #기능4)
                if(grid[location] == 0 ) {
                	coords[x++] = location; //실제 위치 배열에 location저장
                    location += incr; //다음칸 확인
                    if(location >= gridSize) { //경계를 벗어난 경우
                        success = false; //위치 재설정
                    }
                    if(x>0 & (location % gridLength == 0)) {//10의 배수이거나 이미 닷컴이 있는 자리일때
                        success = false; //위치 재설정
                    }
                } else {
                    success = false;
                }
            }
        }
        
        int x = 0; //빅데이터 분석
        int row = 0;
        int column = 0;
        while(x < comSize) { //4번 반복
            grid[coords[x]] = 1; //사용중인 좌표로 설정
            row = (int)(coords[x] / gridLength); //행(세로)값을 설정
            column = coords[x] % gridLength; //열(가로)값을 설정
            temp = String.valueOf(alphabet.charAt(column)); //숫자인 열값을 알파벳으로 변환
            alphaCells.add(temp.concat(Integer.toString(row))); //temp를 알파벳배열에 추가
            x++;
        }
        return alphaCells;
    }
}