
<template>

  <div >
    <form @submit.prevent="onSubmit">
    <Header/>
    <div class="form">
      <h1 class="auth">Регистрация</h1>
      <input v-model="form.name " type="text" id="nameInput"   placeholder="Логин" required>
      <input v-model="form.password" type="password" class="form-control" id="passwordInput" placeholder="Пароль" required>
      <input type="password" placeholder="Повторите пароль">
      <button type="submit" class="form-btn" > <router-link to="/">Зарегистрироваться</router-link></button>


    </div>
    </form>
    <Footer/>
  </div>
</template>
<script>
import Header from "@/components/Header";
import Footer from "@/components/Footer";

import qs from "querystring"

export default {
  name:"Registration",
  components: { Header, Footer},
  data (){
    return{
      title:'Registration',
      form: {
        name: null,
        password: null
      }
    }
  },
  methods: {
    onSubmit() {
      this.$http.post(
          "/user/register",
          qs.stringify(this.form),
          {
            dataType: "x-www-form-urlencoded",
            headers: { 'content-type': 'application/x-www-form-urlencoded' }
          })
          .then(response => {
            if (response.data === "Success")
              this.$router.push({
                name: "Home"
              })
          })
          .catch(e => {
          })
    }
  }
}
</script>
