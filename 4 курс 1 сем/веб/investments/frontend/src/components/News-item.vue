<template>
  <div>
    <p></p>
    <section class="news-item">
      <img class="img-news" v-bind:src="news.image" >

      <div class="tex">
        <div>
          <h2><a class="anews" href="">{{ news.title }}</a></h2>
        </div>
        <div>
          <h5>{{ news.date}}</h5>
        </div>
        <div>
          <h3>{{news.text}}</h3>
        </div>
      </div>
    </section>
    <p></p>
  </div>
</template>

<script>
export default {
  name: "News-item",
  props:{
      news:{
        type: Object,
        required:true
      }
  }
}
</script>

<style scoped>

</style>