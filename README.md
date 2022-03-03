# CRA2022_7th_HelpMe


## ���� ȯ��
�� ������Ʈ�� Visual Studio 2022 �������� ���ߵǾ���.  
(���� ������ ��� �� ��������� v143 ���� ��������� �Ѵ�.)

## ���� ���
C++ 14 �������� �����Ѵ�.
  
### ������
$ EmployeeManager input.txt output.txt
  
<br/>

## Rule
  
### Ground Rule
	- Ŀ�Ը޽����� �ǵ� ǥ���ϱ�
	- ���� ������ ����
	- �ð� ���� �� ��Ű��
	- ���� �����ϴ� �������� �ڵ� �����ϱ�
	- �ǰ��� ������ ���������� ǥ���ϱ�
	- �ڵ帮��� �ִ��� ������ �ϱ�
	- ���� �������� �ڵ帮�� �޾Ƶ��̱�
	- Ī�� �Ƴ��� �ʱ�
  
<br/>

### Commit message Rule
Commit message �� Udacity guide�� ������.  
- [Udacity Git Commit Message Style Guide](https://udacity.github.io/git-styleguide/)  

Commit message ������ Prefix �� ������ ����.
  
```
feat: ���ο� feature  
fix: ���� �� ����   
docs: ���� ���� ����  
style: ����,  �����ݷ� ���� �� �ڵ尡 �ƴ� ��Ÿ�Ͽ� ���õ� ����   
refactor: �����丵 �ڵ�  
test: �׽�Ʈ �ڵ� �߰� �� �����丵 �׽�Ʈ ��  
chore: build task ����, ������Ʈ �Ŵ��� ���� ���� ��  
```

ex)
```
feat: Add feature

body
```
  
<br/>

### PR Rule
PR���� git-flow ����� ������.
- [git-flow](https://www.howdy-mj.me/git/git-flow/)
  
�귣ġ ���� �Ʒ��� ������ "/" �� ����ؼ� �����Ѵ�.
```
master : ��ǰ���� ��õ� �� �ִ� �귣ġ
develop : ���� ��� ������ �����ϴ� �귣ġ
feature : ����� �����ϴ� �귣ġ
release : �̹� ��� ������ �غ��ϴ� �귣ġ
hotfix : ��� �������� �߻��� ���׸� ���� �ϴ� �귣ġ
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
PR�� code coverage ������ �����ؾ� �Ѵ�.

#### Code Coverage ���� 
- Function Coverage: 95%
- Line Coverage: 90%

#### Code Coverage �������
Visual studio ���� �����ϴ� ���� ���
  
<br/>

### Coding Style
DS C++ Coding Style ���� ������.
    
<br/>

### TDD
- ��� ����� TDD�� ����ؼ� ���ߵǾ�� �Ѵ�.
- ����� �߰��Ǿ��� ��� ���� commit�� test case���� �߰��Ǿ�� �Ѵ�.
- Test case�� ���������� �������� �ؾ��Ѵ�.
- Google test �� ����Ѵ�.
