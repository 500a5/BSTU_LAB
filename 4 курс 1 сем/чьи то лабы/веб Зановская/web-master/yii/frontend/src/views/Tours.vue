<template>
    <main role="main">
    <div class="container marketing">

        <div v-for = "item in models" :key="item.id">
            <hr class="featurette-divider">

            <div class="featurette item">

                <div class="col-lg-6 col-xs-12">
                    <div v-if="item.image">
                        <img :src="item.image" class="img-fluid">
                    </div>
                </div>
                <div class="col-lg-5  col-xs-12">
                    <h2 class="featurette-heading">
                        {{item.title}}
                    </h2>
                    <p class="lead">
                        {{item.text}}
                    </p>
                </div>
            </div>

                <button type="button" class="button btn-bl btn-lg btn-block">
                    <router-link :to="{name: 'description', params: {id: item.id}}">
                        <p class="text">Хочу!</p>
                    </router-link>
                </button>

        </div>
    </div>

    </main>
</template>

<script>
    import HTTP from "../components/http";

    export default {
        name: "Tours",
        data() {
            return {
                models: [],
                items:[]
            };
        },
        created() {
            HTTP.get('/tours') //запрос апи, то что вернули записали в моделс
                .then(response => (this.models = response.data))
        }
    }
</script>

<style scoped>
    .item {
        display: -ms-flexbox;
        display: flex;
        -ms-flex-wrap: wrap;
        flex-wrap: wrap;
        flex-direction: row;
        margin-right: -15px;
        margin-left: -15px;
        margin-bottom: 20px;
        justify-content: space-between;
    }
    .bd-placeholder-img {
        font-size: 1.125rem;
        text-anchor: middle;
        -webkit-user-select: none;
        -moz-user-select: none;
        -ms-user-select: none;
        user-select: none;
    }
    .featurette-divider {
        margin: 5rem 0;
    }
    .header-mrg {
        margin-bottom: 30px;
    }
    @media (min-width: 768px) {
        .bd-placeholder-img-lg {
            font-size: 3.5rem;
        }

    }
    @media (min-width: 62em){
        .featurette-heading {
            margin-top: 3rem;
        }
    }

    @media (max-width :768px) {
        .item {
            flex-direction: column;
        }
    }

    .button {
        border-width: 0;
        border-radius: 10px;
        color: #fff;
    }

    .btn-teal {
        background-color: teal;
    }

    .btn-ocher {
        background-color: #5a4030;
    }
    .btn-dbr {
        background-color: #342b2c;
    }
    .btn-vlt{
        background-color: #4d3858;
    }

    .btn-bl {
        background-color: #1e5d64;
    }
    .text {
        margin:0;
        color: #fff;
    }
</style>