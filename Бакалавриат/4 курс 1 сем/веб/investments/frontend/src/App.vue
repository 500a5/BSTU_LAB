
<template>
    <router-view/>
</template>
<script>
import qs from "querystring"
export default {
  data() {
    return {
      form: {
        name: null,
        password: null
      },
      isLogged: false
    }
  },
  methods: {
    onSubmit() {
      this.$http.get("/users/login", {
        params: this.form
      })
          .then(response => {
            if (response.data === "Success") {
              this.isLogged = true
              this.$router.push({
                name: "Home"
              })
            }
          })
    },
    logout() {
      this.isLogged = false
    }
  }
}
</script>
<style lang="css">
@import "assets/css/app.css";
@import "assets/css/authorization.css";
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
}

#nav {
  padding: 30px;
}

#nav a {
  font-weight: bold;
  color: #2c3e50;
}

#nav a.router-link-exact-active {
  color: #42b983;
}
</style>
<script>
import News from "@/components/News";
import Authorization from "@/views/Authorization";
import Footer from "@/components/Footer";
import Registration from "@/views/Registration";
import Header from "@/components/Header";

export default {
  components: {Header, Footer, News, Authorization, Registration}
}
</script>