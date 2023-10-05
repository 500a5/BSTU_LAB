let users = [1,2,3]
users = users.map(item=>item+10)


//console.log(users)

const funcItem = function (item){

}

const funcItem1 = (item) => {

}

const funcItem2 = (item) => item+10

const funcItem3 = item => item+10

const user =  {
    name: 'Иван',
    age: 21,
    language: ['ru', 'en'],
    getAge(){
        return this.age
    },

    equalsAge(age){
        return age === this.age
    },

    isLanguage(lang){
        return this.language.indexOf(lang)!==-1
    }
}
console.log(user.equalsAge(21))