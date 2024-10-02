

<template>
 <section>

   <NewsItem
    v-for="news of news"
    v-bind:news="news"
   />
 </section>
</template>

<script>


import NewsItem from "@/components/News-item";
import axios from "axios"

export default {
  name: 'News',
  data(){
    return {
      news: []
    }
  },
  created() {
    let config = {
      headers: {
        'Access-Control-Allow-Origin': 'http://localhost:8080',
        'Access-Control-Allow-Methods': 'POST, GET, OPTIONS'
      }
    }

    axios.get("http://localhost:8081/api/news/list", config)
        .then(response => {
          console.log(response.data)
          this.news = response.data
        })
        .catch(e => {
        })
  },
  components: {
    NewsItem

  }
}
</script>
