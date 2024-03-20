                        # GIT에 대한 조사
## VCS(Version Control System)
* VCS(Version Control System)는 소프트웨어 개발 과정에서 소스 코드와 같은 파일들의 변경사항을 관리하고 추적하는 시스템입니다. 주로 프로젝트의 이력을 관리하고 여러 명의 개발자가 협업할 수 있도록 도와줍니다.

## DVCS와 VCS의 차의점
* DVCS는 분산 버전 관리 시스템을 의미하고, 여러 사용자가 동시에 작업하고 서로 다른 저장소에서 변경 사항을 추적하고 병합할 수 있는 시스템입니다. 대표적으로는 DVCS로는 Git이 있습니다.
반면 VCS는 버전 관리 시스템을 의미하고, 파일의 변경 사항을 추적하고 관리하는 시스템을 말합니다. VCS에는 중앙 집중식 버전 관리 시스템(CVCS)과 분산 버전 관리 시스템(DVCS)이 있습니다. DVCS는 중앙 서버 없이 각각의 사용자가 로컬 저장소를 가지며 작업하고, 필요할 때 변경 사항을 주고받을 수 있는 반면, CVCS는 중앙 서버에 모든 변경 사항이 저장되며 사용자는 중앙 서버에서 파일을 가져오고 변경 사항을 반영합니다

## Remote Repository 생성하기
* Git 서비스(예: GitHub, GitLab 등)에 로그인하여 새로운 Repository를 생성합니다. 이때, Repository의 이름과 
설명을 설정할 수 있습니다.

## Local Repository 초기화 및 Remote Repository와 연결하기
* git bash를 통해 원하는 디렉토리로 간다
* git init 이라는 명령어를 통해 git 저장소 초기화
* git remote add sdh020802 https://github.com/sdh020802/YH24-GameEngine.git 이것을 사용해 원격저장소 추가
* git add . 을 사용해 파일을 추가한후 git commit이란 명령어로 커밋

## 마크다운표기법
* 헤더(Header): #을 사용하여 헤더를 표시합니다.
* 볼드(Bold): **   ** 또는 __   __로 감싼 텍스트는 볼드로 표시됩니다.
* 이탤릭(Italic): *   * 또는 _텍스트_로 감싼 텍스트는 이탤릭으로 표시됩니다.
* 링크(Link): [링크 텍스트](링크 URL)를 사용하여 링크를 표시합니다.
* 이미지(Image): ![대체 텍스트](이미지 URL)를 사용하여 이미지를 삽입합니다.
* 목록(List): 순서 없는 목록은 - 또는 *로, 순서 있는 목록은 숫자로 표시합니다.
* 인용(Blockquote): >를 사용하여 인용구를 표시합니다.
* 코드(Code): `로 감싼 텍스트는 인라인 코드로 표시되며, 코드 블록은 ```로 시작하여 ```로 끝납니다.
* 수평선(Horizontal Rule): --- 또는 ***를 사용하여 수평선을 추가합니다.

