<template>
  <div>
  <Header/>

  <main class="container">
    <News/>
  </main>
  <Footer/>
  </div>
</template>
<script>
import Header from "@/components/Header";
import Footer from "@/components/Footer";
import News from "@/components/News";
export default {
  name:"Home",
  components: {Footer, Header, News},
  data (){
    return{
      title:'Home'
    }
  }
}
</script>