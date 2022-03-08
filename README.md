# CRA2022_7th_HelpMe


## 개발 환경
본 프로젝트는 Visual Studio 2022 버전에서 개발되었다.  
(하위 버전을 사용 시 빌드버전을 v143 으로 변경해줘야 한다.)

## 개발 언어
C++ 14 기준으로 개발한다.
  
### 실행방법
$ EmployeeManager input.txt output.txt
  
<br/>

## Rule
  
### Ground Rule
	- 커밋메시지에 의도 표현하기
	- 빨리 끝내고 쉬기
	- 시간 제한 잘 지키기
	- 서로 존중하는 마음으로 코드 리뷰하기
	- 의견이 있으면 적극적으로 표현하기
	- 코드리뷰는 최대한 빠르게 하기
	- 열린 마음으로 코드리뷰 받아들이기
	- 칭찬 아끼지 않기
  
<br/>

### Commit message Rule
Commit message 는 Udacity guide를 따른다.  
- [Udacity Git Commit Message Style Guide](https://udacity.github.io/git-styleguide/)  

Commit message 제목의 Prefix 는 다음과 같다.
  
```
feat: 새로운 feature  
fix: 버그 등 수정   
docs: 문서 내용 변경  
style: 포맷,  세미콜론 수정 등 코드가 아닌 스타일에 관련된 수정   
refactor: 리팩토링 코드  
test: 테스트 코드 추가 및 리팩토링 테스트 등  
chore: build task 수정, 프로젝트 매니저 설정 수정 등  
```

ex)
```
feat: Add feature

body
```
  
<br/>

### PR Rule
PR룰은 git-flow 방식을 따른다.
- [git-flow](https://www.howdy-mj.me/git/git-flow/)
  
브랜치 명은 아래와 같으며 "/" 를 사용해서 구분한다.
```
master : 제품으로 출시될 수 있는 브랜치
develop : 다음 출시 버전을 개발하는 브랜치
feature : 기능을 개발하는 브랜치
release : 이번 출시 버전을 준비하는 브랜치
hotfix : 출시 버전에서 발생한 버그를 수정 하는 브랜치
```
  
ex) 
```
develop
feature/add_readme
feature/refactor_main
feature/fix_main
release/v0.1
```

<br/>
  
### Code Coverage
PR은 code coverage 기준을 만족해야 한다.

#### Code Coverage 기준 
- Function Coverage: 95%
- Line Coverage: 90%

#### Code Coverage 측정방법
Visual studio 에서 지원하는 툴을 사용
  
<br/>

### Coding Style
DS C++ Coding Style 룰을 따른다.
    
<br/>

### TDD
- 모든 기능은 TDD를 사용해서 개발되어야 한다.
- 기능이 추가되었을 경우 같은 commit에 test case또한 추가되어야 한다.
- Test case는 지속적으로 유지보수 해야한다.
- Google test 를 사용한다.
