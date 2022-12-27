package java_Week5;

import java.util.*;

public class DotCom {
    private ArrayList<String> locationCells; //셀 위치가 들어있음
    private String name;
    
    public void setLocationCells(ArrayList loc) {
        locationCells = loc;
    }
    
    public void setName(String n) { //빅데이터 분석
        name = n;
    }
    
    public String checkYourself(String userInput) {
        String status = "miss";
        int index = locationCells.indexOf(userInput); //추측한 위치를 index에 저장
        
        if(index >= 0) {
            locationCells.remove(index); //추측한 위치 제거
            if(locationCells.isEmpty()) { //모든 위치를 맞췄는지 확인
                status = "kill"; //추측한 위치가 4칸중 1,2,3칸이 맞았을때
                System.out.println(name + "을 가라앉혔습니다");
            } else {
                status = "hit"; //추측한 위치가 4칸 모두 맞았을때
            }
        }
        return status; //kill, hit, miss중 하나의 상태를 리턴
    }
}