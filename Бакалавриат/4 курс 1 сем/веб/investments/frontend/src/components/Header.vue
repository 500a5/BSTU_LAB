<template>
  <header>
    <div class="header">
      <img src="img/logo.png" width="20%">
      <div class="authorization">
        <router-link to="/Registration" class="authorization">Регистрация</router-link>
        <b class="authorization">/</b>
        <router-link to="/Authorization" class="authorization">Вход</router-link>
      </div>
    </div>
    <nav>
      <ul>
        <li> <router-link to="/" >Новости</router-link></li>
        <li><a href="">Аналитика</a></li>
        <li><a href="">Курсы валют</a></li>
        <li><a href="">Брокеры</a></li>
        <li><a href="">О компании</a></li>
      </ul>
    </nav>

  </header>
</template>

<script>
import Authorization from "@/views/Authorization";
import Registration from "@/views/Registration";
export default {
  name: "Header",
  data (){
    return{
      title:'Header'
    }
  }

}
</script>

<style scoped>

</style>