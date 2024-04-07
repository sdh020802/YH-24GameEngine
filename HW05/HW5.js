var canvas = document.getElementById("GameScreenCanvas");
var ctx = canvas.getContext("2d");

var rotateVar = 0.0;
var PI = 3.14;

ctx.translate(canvas.width/2, canvas.height/2);

function drawRect(angle, offsetX, offsetY) {
    ctx.fillStyle = "red"; 
    ctx.save();
    ctx.rotate(angle);
    ctx.fillRect(-40 + offsetX, -40 + offsetY, 100, 100);
    ctx.restore();
}

function drawRect1(angle1, offsetX, offsetY) {
    ctx.fillStyle = "green"; 
    ctx.save();
    ctx.rotate(angle1);
    ctx.translate(offsetX, offsetY);
    ctx.fillRect(-300, -100, 100, 100);
    ctx.restore();
}

function drawRect2(angle2,) {
    ctx.fillStyle = "blue"; 
    ctx.save();
    ctx.translate(-250, -100);
    ctx.rotate(angle2);
    ctx.fillRect(-50, 0, 80, 80);
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
    drawRect1(rotAngle1, 0, 0);
    requestAnimationFrame(draw1);
}

function draw2() {
    rotAngle2 += PI / 100;
    drawRect2(rotAngle2, 0, 0);
    requestAnimationFrame(draw2);
}

draw();
draw1();
draw2();
