var canvas = document.getElementById("GameScreenCanvas");
var ctx = canvas.getContext("2d");

// 캔버스의 중앙으로 좌표계 이동
ctx.translate(canvas.width / 2, canvas.height / 2);

// 별 모양 그리기
ctx.beginPath();
ctx.moveTo(0, -40); // 별의 맨 위로 이동
ctx.lineTo(15, 25); // 오른쪽 아래로 선 그리기
ctx.lineTo(-24, -15); // 왼쪽 아래로 선 그리기
ctx.lineTo(24, -15); // 오른쪽 위로 선 그리기
ctx.lineTo(-15, 25); // 왼쪽 위로 선 그리기
ctx.closePath(); // 별 모양 마무리
ctx.lineWidth = 5; // 선의 두께 설정
ctx.stroke(); // 선 그리기
ctx.fillStyle = 'yellow'; // 채우기 색상 설정
ctx.fill(); // 내부 채우기

// 하트 그리기 함수
function drawHeart(x, y) {
    ctx.beginPath();
    ctx.moveTo(x, y - 50);
    ctx.bezierCurveTo(x + 50, y - 80, x + 90, y - 10, x, y + 40);
    ctx.bezierCurveTo(x - 90, y - 10, x - 50, y - 80, x, y - 50);
    ctx.fillStyle = "red";
    ctx.fill();
    ctx.closePath();
}

// 버튼 그리기 함수
function drawButton() {
    ctx.fillStyle = "rgb(180, 180, 180)"; // 버튼 색상
    ctx.fillRect(-50, 200, 100, 50); // 버튼 위치 및 크기

    // 버튼 텍스트
    ctx.fillStyle = "white";
    ctx.font = "20px Arial";
    ctx.textAlign = "center";
    ctx.fillText("시작", 0, 235);
}

// F5를 누를 때마다 하트를 랜덤한 위치에 그리기
document.addEventListener("key", function(event) {
    if (event.key === "F5") { // F5의 keyCode는 116입니다.
        // 랜덤 위치에 하트 그리기
        var randomX = Math.random() * canvas.width - canvas.width / 2;
        var randomY = Math.random() * canvas.height - canvas.height / 2;
        drawHeart(randomX, randomY);
    }
});

// 페이지가 로드될 때 초기 하트를 그립니다.
var initialX = Math.random() * canvas.width - canvas.width / 2;
var initialY = Math.random() * canvas.height - canvas.height / 2;
drawHeart(initialX, initialY);

// 초기 버튼 그리기
drawButton();

// 마우스 오버 이벤트
canvas.addEventListener("mousemove", function(event) {
    var rect = canvas.getBoundingClientRect();
    var mouseX = event.clientX - rect.left;
    var mouseY = event.clientY - rect.top;

    if (mouseX >= canvas.width / 2 - 50 && mouseX <= canvas.width / 2 + 50 && mouseY >= canvas.height / 2 + 200 && mouseY <= canvas.height / 2 + 250) {
        // 버튼에 마우스가 있을 때 색상 변경
        ctx.fillStyle = "rgb(248, 203, 178)";
        ctx.fillRect(-50, 200, 100, 50);
        ctx.fillStyle = "white";
        ctx.fillText("시작", 0, 235);
    } else {
        // 버튼에 마우스가 없을 때 기본 색상으로 변경
        ctx.fillStyle = "rgb(180, 180, 180)";
        ctx.fillRect(-50, 200, 100, 50);
        ctx.fillStyle = "white";
        ctx.fillText("시작", 0, 235);
    }
});

// 마우스 클릭 이벤트
canvas.addEventListener("click", function(event) {
    var rect = canvas.getBoundingClientRect();
    var mouseX = event.clientX - rect.left;
    var mouseY = event.clientY - rect.top;

    if (mouseX >= canvas.width / 2 - 50 && mouseX <= canvas.width / 2 + 50 && mouseY >= canvas.height / 2 + 200 && mouseY <= canvas.height / 2 + 250) {
        // 버튼 클릭 시 색상 변경
        ctx.fillStyle = "rgb(0, 32, 96)";
        ctx.fillRect(-50, 200, 100, 50);
        ctx.fillStyle = "white";
        ctx.fillText("시작", 0, 235);
        
        // 1초 후에 이전 화면으로 이동
        setTimeout(function() {
            // 이전 화면으로 이동하는 코드 작성
        }, 1000);
    }
});