function Vector2D(x,y) {this.x = x; this.y = y;}
Vector2D.prototype = {
	lengthSquared: function(){return this.x*this.x + this.y*this.y;},
	length: function(){return Math.sqrt(this.lengthSquared());},
	clone: function(){return new Vector2D(this.x,this.y);},
	negate: function(){this.x = - this.x; this.y = - this.y;},
	unit: function() {
		var length = this.length();
		if (length > 0) return new Vector2D(this.x/length,this.y/length);
		return new Vector2D(0,0);
	},
	normalize: function() {
		var length = this.length();
		if (length > 0) {this.x /= length; this.y /= length;}
		return this.length();
	},
	incrementBy: function(vec) {this.x += vec.x; this.y += vec.y;},
	decrementBy: function(vec) {this.x -= vec.x; this.y -= vec.y;},
	scaleBy: function(k) {this.x *= k; this.y *= k;},
	dot: function(vec) {return this.x*vec.x + this.y*vec.y;},
	add: function(vec) {return new Vector2D(this.x + vec.x,this.y + vec.y);},
	subtract: function(vec) {return new Vector2D(this.x - vec.x,this.y - vec.y);},
	multiply: function(k) {return new Vector2D(this.x * k,this.y * k);},
	addScaled: function(vec, k) {return new Vector2D(this.x + vec.x * k, this.y + vec.y * k);},
	perp: function(k){
		var length = this.length();
		if (length <= 0) return new Vector2D(0,0);
		return new Vector2D(this.y / length * k, -this.x / length * k);
	},
	rotate: function(angle){return new Vector2D(this.x*Math.cos(angle)-this.y*Math.sin(angle),this.x*Math.sin(angle)+this.y*Math.cos(angle));}
};

Vector2D.zero = function() {return new Vector2D(0,0);}
Vector2D.add = function(arr){
	var sum = new Vector2D(0,0);
	for (var i=0; i<arr.length; i++) sum.incrementBy(arr[i]);
	return sum;
}
Vector2D.distance = function(vec1,vec2){return (vec1.subtract(vec2)).length();}
Vector2D.angle    = function(vec1,vec2){return Math.acos(vec1.dot(vec2)/(vec1.length()*vec2.length()));}
Vector2D.polar    = function(mag,angle){return new Vector2D(mag*Math.cos(angle), mag*Math.sin(angle));}

function Ball(radius,color,mass,gradient){
	if(typeof(radius)==='undefined') radius = 20;
	if(typeof(color)==='undefined') color = '#0000ff';
	if(typeof(mass)==='undefined') mass = 1;
	if(typeof(gradient)==='undefined') gradient = false;
	this.radius = radius;
	this.color = color;
	this.mass = mass;
	this.gradient = gradient;
	this.x = 0;
	this.y = 0;
	this.vx = 0;
	this.vy = 0;
}

Ball.prototype = {
	get pos2D (){return new Vector2D(this.x,this.y);},
	set pos2D (pos){this.x = pos.x; this.y = pos.y;},
	get vel2D (){return new Vector2D(this.vx,this.vy);},
	set vel2D (vel){this.vx = vel.x; this.vy = vel.y;},
	draw: function (context) {
		if (this.gradient){
			var d = this.radius / 3;
			grd = context.createRadialGradient(this.x+d,this.y-d,d/2,this.x+d,this.y-d,this.radius);
			grd.addColorStop(0,'#ffffff');
			grd.addColorStop(1,this.color);
			context.fillStyle = grd;
		}else{
			context.fillStyle = this.color;
		}
		context.beginPath();
		context.arc(this.x, this.y, this.radius, 0, 2*Math.PI, true);
		context.closePath();
		context.fill();
	}
};
