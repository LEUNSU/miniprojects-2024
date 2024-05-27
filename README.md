# 미니프로젝트 2024
IoT 개발자 미니프로젝트 리포지토리

## 1일차
- IoT 프로젝트 개요

    ![IoT프로젝트](https://raw.githubusercontent.com/LEUNSU/miniprojects-2024/main/images/mp001.png) 

    1. IoT기기 구성 - 아두이노, 라즈베리파이 등 IoT장비들과 연결
    2. 서버 구성 - IoT기기와 통신, DB구성, 데이터 수집 앱 개발 
    3. 모니터링 구성 - 실시간 모니터링/제어 앱, 전체 연결

- 조별 미니프로젝트
    - 5월 28일 (40시간)
    - 구체적으로 어떤 디바이스 구성, 데이터 수집, 모니터링 계획
    - 8월말 정도에 끝나는 프로젝트 일정 계획
    - 요구사항 리스트, 기능명세, UI/UX 디자인, DB설계 문서하나로 통합
    - 5월 28일 오후 각 조별로 파워포인트/프레젠테이션 10분 발표
    - 요구사항 리스트 문서전달 
    - 기능명세 문서 
    - DB설계 ERD 또는 SSMS 물리적 DB설계
    - UI/UX디자인 16일(목) 내용전달

## 2일차
- 미니프로젝트 
    - 프로젝트 문서
    - Notion 팀 프로젝트 템플릿 활용
    - UI/UX디자인 툴 설명
        - https://ovenapp.io/ 카카오
        - https://www.figma.com/ 피그마
            - 피그마 단축키 :
                - V - 선택도구
                - A - 직선도구
                - T - 텍스트도구
                - Space + Drag - 마우스 커서에 따라 원하는 영역으로 이동
                - Ctrl + R - 레이어 이름 변경
                - Ctrl + G - 객체 그룹화
                - Ctrl + Shift + G - 객체 그룹 해제
                - Ctrl + D - 선택한 객체 복사
                - Ctrl + [ - 선택한 객체 뒤로 보내기
                - Ctrl + ] - 선택한 객체 앞으로 보내기
        - https://app.moqups.com/ 목업디자인 사이트
    - 프레젠테이션
        - https://www.miricanvas.com/ko 미리캔버스 활용 추천
    - 라즈베리파이(RPi) 리셋팅, 네트워크 설정, VNC(OS UI작업)

- 스마트홈 연동 클래스 미니프로젝트
    1. 요구사항 정의, 기능명세
    2. UI/UX 디자인
        - RPi는 디자인 없음(콘솔)
        - 데이터 수신앱
        - 모니터링 앱
    3. DB설계
    4. RPi 셋팅(Network)
    5. RPi GPIO, IoT디바이스 연결(카메라, HDT센서, RGB LED, ...)
    6. RPi 스마트홈 데이터 전송 파이썬 프로그래밍
    7. PC(Server) 데이터 수신 C# 프로그래밍
    8. 모니터링 앱 개발(수신 및 송신)

## 3일차
- 미니프로젝트 
    - 실무 프로젝트 문서
    - Jira 사용법
    - 조별로 진행

- 라즈베리파이 셋팅
    1. RPi 기본구성 - RPi + MicroSD + Power
    2. RPi 기본 셋팅
        - 한글화
        - 키보드 변경
        - 화면사이즈 변경(RealVNC)
        - Pi Apps 앱설치 도우미 앱
        - Github Desktop, VS Code
        - 네트워크 확인
        - RealVNC Server 자동실행 설정

- 스마트홈 연동 클래스 미니프로젝트
    - RPi 셋팅... 진행 

## 4일차
- 라즈베리파이 IoT장비 설치
    - [x] 라즈베리파이 카메라  
    - [x] GPIO HAT  
    - [ ] 브레드보드와 연결  
    - [ ] DHT11센서 
    - [X] RGB LED 모듈
        - V - SV 연결
        - R - GPIO4 연결
        - G - GPIO5 연결
        - B - GPIO6 연결

## 5일차
- 라즈베리파이 IoT장비 설치
    - [X] DHT 센서
    - GND - GND 8개중 아무데나 연결
    - VCC - 5V 연결
    - S - GPIO8 연결

## 6, 7일차
- 네트워크 대공사
    - [x] 개인공유기, PC, 라즈베리파이

- 스마트홈 연동 클래스 미니프로젝트
    - 온습도 센서, RGB LED
    - PRi <--> Windows 통신(MQTT)
    - WPF 모니터링 앱

- IoT 기기간 통신방법
    - Modbus - 시리얼통신으로 데이터 전송(완전 구식)
    - OPC UA - Modbus통신 불편한 점 개선(아주 복잡)
    - **MQTT** - 가장 편리! AWS IoT, Azure IoT 클라우드 산업계 표준으로 사용

- MQTT 통신
    - [x] Mosquitto Broker 설치
        - mosquitto.conf : listener 1883 0.0.0.0, allow_anonymous true
        - 방화벽 인바운드 열기
    - [ ] RPi : paho-mqtt 패키지 설치, 송신(publisher)
    - Win : MQTT.NET Nuget패키지 설치, 수신(subscriber)