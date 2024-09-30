
const sortByStr = (label, subLabel=null) => {
	return {
		sorter: (o1, o2) => {
			let s1 = o1[label]
			let s2 = o2[label]
			if (subLabel !== null) {
				s1 = s1[subLabel]
				s2 = s2[subLabel]
			}
			if (s1 < s2) return -1
			if (s1 > s2) return 1
			return 0
		},
		sortDirections: ['descend', 'ascend'],
	}
}


const sortByDate = (label, subLabel=null) => {
	return {
		sorter: (o1, o2) => {
			let d1 = o1[label]
			let d2 = o2[label]
			if (subLabel !== null) {
				d1 = d1[subLabel]
				d2 = d2[subLabel]
			}
			if (d1 < d2) return -1
			if (d1 > d2) return 1
			return 0
		},
		sortDirections: ['descend', 'ascend'],
	}
}

const sortByDigit = (label, subLabel=null) => {
	return {
		sorter: (o1, o2) => {
			let s1 = o1[label]
			let s2 = o2[label]
			if (subLabel !== null) {
				s1 = s1[subLabel]
				s2 = s2[subLabel]
			}
			return s1 - s2
		},
		sortDirections: ['descend', 'ascend'],
	}
}


export {sortByStr, sortByDate, sortByDigit}
