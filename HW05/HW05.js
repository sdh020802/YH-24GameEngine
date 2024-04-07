var canvas = document.getElementById("GameScreenCanvas");
var ctx = canvas.getContext("2d");

var rotateVar = 0.0;
var PI = 3.14;

ctx.translate(canvas.width/2, canvas.height/2); // 중앙 위치로 이동

function drawRect(angle, offsetX, offsetY) {
    ctx.fillStyle = "red"; 
    ctx.save();
    ctx.rotate(angle);
    ctx.fillRect(-40 + offsetX, -40 + offsetY, 100, 100);
    ctx.restore();
}

function drawRect1(angle1) {
    ctx.fillStyle = "green"; 
    ctx.save();
    ctx.rotate(angle1);
    ctx.fillRect(-300, -100, 100, 100);
    ctx.restore();
}

function drawRect2(angle2, offsetX, offsetY) {
    ctx.fillStyle = "blue"; 
    ctx.save();
    ctx.translate(-250, -50); // 두 번째 사각형의 위치를 기준으로 설정
    ctx.rotate(angle2); // 세 번째 사각형의 회전 각도를 기준으로 설정
    ctx.fillRect(-300 + offsetX, -100 + offsetY, 80, 80); // 위치 보정
    ctx.restore();
}

var rotAngle = 0;
var rotAngle1 = 0;
var rotAngle2 = 0;

function draw() {
    rotAngle += PI / 100;
    ctx.clearRect(-canvas.width/2, -canvas.height/2, canvas.width, canvas.height);
    drawRect(rotAngle, 0, 0);
    requestAnimationFrame(draw);   
}

function draw1() {
    rotAngle1 += PI / 200;
    drawRect1(rotAngle1);
    requestAnimationFrame(draw1);
}

function draw2() {
    rotAngle2 += PI / 100;
    drawRect2(rotAngle2, 0, 0); // 두 번째 사각형의 위치를 offsetX, offsetY로 설정
    requestAnimationFrame(draw2);
}

draw();
draw1();
draw2();