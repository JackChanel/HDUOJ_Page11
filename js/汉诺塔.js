/**
 * @param {number[]} A
 * @param {number[]} B
 * @param {number[]} C
 * @return {void} Do not return anything, modify C in-place instead.
 */
var hanota = function (A, B, C) {
	const movea2c = (size, A, B, C) => {
		if (size == 1) {
			const u = A.pop()
			C.push(u)
			return
		} else {
			const u = A.pop()
			movea2c(size - 1, A, B, C)
			C.push(u)
		}
	}
	const size = A.length
	movea2c(size, A, B, C)
}

const A = [1, 2, 3, 4, 5, 6]
const B = []
const C = []

hanota(A, B, C)
console.log(C)
