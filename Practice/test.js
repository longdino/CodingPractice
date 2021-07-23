
var e = 10;
function sum(a){
	return function sum2(b){
		return function sum3(c){
			return function sum4(d){
				return a + b + c + d + e;
			}
		}
	}
}

var sum2 = sum(1);
var sum3 = sum2(2);
var sum4 = sum3(3);
var result = sum4(4);

console.log(sum2);
console.log(sum3);
console.log(sum4);
console.log(result);
