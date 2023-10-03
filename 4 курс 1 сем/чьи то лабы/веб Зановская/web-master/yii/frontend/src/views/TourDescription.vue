<template>
    <article class="article">
        <h1>{{model.title}}</h1>
        <div v-html="model.text"></div>
    </article>
</template>

<script>
    import HTTP from "../components/http";

    export default {
        name: "TourDescription",
        data() {
            return {
                model: { }
            };
        },
        created() {
            var id = this.$route.params.id;
            HTTP.get('/tours/' + id)
                .then(response => (this.model = response.data));
        }
    }
</script>

<style scoped>

</style>