var canvas = document.getElementById("GameScreenCanvas");
var ctx = canvas.getContext("2d");

var colors = ["blue", "red", "green", "yellow", "purple", "orange"];

class HeartObject {
    constructor(colorIndex, radius){
        this.color = colors[colorIndex];
        this.radius = radius;
    }
    
    draw(positionX, positionY) {
        ctx.beginPath();
        for (var angle = 0; angle < Math.PI * 2; angle += 0.01) {
            var x = positionX + this.radius * (16 * Math.pow(Math.sin(angle), 3));
            var y = positionY - this.radius * (13 * Math.cos(angle) - 5 * Math.cos(2 * angle) - 2 * Math.cos(3 * angle) - Math.cos(4 * angle));
            ctx.lineTo(x, y);
        }
        ctx.fillStyle = this.color;
        ctx.fill();
        ctx.closePath();
    }
}

function render(mouseX, mouseY) {
    ctx.clearRect(0, 0, canvas.width, canvas.height); 
    var heart = new HeartObject(Math.floor(Math.random() * colors.length), 10);
    heart.draw(mouseX, mouseY);
    requestAnimationFrame(function() {
        render(mouseX, mouseY);
    });
}

canvas.addEventListener('mousemove', function(event) {
    var rect = canvas.getBoundingClientRect();
    var mouseX = event.clientX - rect.left;
    var mouseY = event.clientY - rect.top;
    render(mouseX, mouseY);
});