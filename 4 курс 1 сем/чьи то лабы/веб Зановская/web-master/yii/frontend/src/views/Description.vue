<template>
    <div class="album py-5 bg-light">

        <div class="container">
            <div class="row">

                <div  v-for="item in model" :key="item.id" class="col-md-4">

                    <div class="card mb-4 shadow-sm">

<!--                        <img src="../images/crimea/anastasiia-rozumna-f08DupJ2fnI-unsplash (1).jpg" class="img-fluid"/>-->
                        <div v-if="item.image">
                            <img :src="item.image" class="img-fluid">
                        </div>
                        <div class="card-body">
                            <p class="card-text">{{item.description}} </p>

                        </div>
                    </div>
                </div>

                <button type="button" class="button btn-bl btn-lg btn-block">
                    <router-link :to="{name: 'cart', params: {id: this.id}}">
                        <p class="text">Отправить заявку</p>
                    </router-link>
                </button>
            </div>
        </div>
    </div>
</template>

<script>
    import HTTP from "../components/http";

    export default {
        name: "Description",
        data() {
            return {
                model: { },
                id:''
            };
        },
        created() {
            this.id = this.$route.params.id;
            HTTP.get('/description/' + this.id)
                .then(response => (this.model = response.data));
        }
    }
</script>
<style>

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
<style scoped>
    .title {
        margin-bottom: 50px;
    }
</style>