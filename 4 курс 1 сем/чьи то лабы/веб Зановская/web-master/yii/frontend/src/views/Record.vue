<template>
    <section class="cart">
        <h4 v-if="result === 'success'">Заявка успешно отправлена</h4>
        <form @submit.prevent="send" v-if="result !== 'success'">
            <div class="form-group">
                <label>
                    <input type="text" placeholder="Имя" v-model="name">
                </label>
                <div class="error" v-if="$v.name.$anyError && !$v.name.required">Заполните «Имя».</div>
                <div class="error" v-if="$v.name.$anyError && !$v.name.maxLength">Максимальная длина 128 символов.</div>
            </div>
            <div class="form-group">
                <label>
                    <input type="email" placeholder="Email" v-model="email">
                </label>
                <div class="error" v-if="$v.email.$anyError && !$v.email.required">Заполните «Email».</div>
                <div class="error" v-if="$v.email.$anyError && !$v.email.email">Некорректный Email.</div>
            </div>
            <div class="form-group">
                <label>
                    <input type="text" placeholder="Телефон" v-model="phone">
                </label>
                <div class="error" v-if="$v.phone.$anyError && !$v.phone.required">Заполните «Телефон».</div>
                <div class="error" v-if="$v.phone.$anyError && !$v.phone.customValidate">Число должно быть > 0.</div>
            </div>


<!--            <div style="width:205px; margin-left: auto; margin-right:auto;margin-bottom: 20px">-->
<!--                <label for="Category">Тур</label>-->
<!--                <select class="form-control" id="Category" v-model="categoryId">-->
<!--                    <option v-for="category in model" v-bind:key="category.id" v-bind:value="category.id">{{category.name}}</option>-->
<!--                </select>-->
<!--            </div>-->
            <div class="form-group">
                <button class="btn btn-lg btn-primary">Отправить</button>
            </div>
        </form>
    </section>
</template>

<script>
    import {HTTP} from "../components/http";
    import {required, maxLength, email} from "vuelidate/src/validators";
    import {req} from 'vuelidate/src/validators/common';

    // custom validator
    const customValidate = (value) => {
        return !req(value) || parseInt(value) > 0;
    };

    export default {
        name: "Record",
        data() {
            return {
                name: '',
                email: '',
                phone: '',
                categoryId: '',
                result: '',
                model:{}
            };
        },
        validations: {
            name: {
                required,
                maxLength: maxLength(128)
            },
            email: {
                required,
                email: email
            },
            phone: {
                required,
                customValidate
            },
        },
        methods: {
            send: function () {
                this.$v.$touch();
                if (!this.$v.$invalid) {
                    HTTP.post('/record/record', {
                        name: this.name,
                        email: this.email,
                        phone: this.phone,
                        categoryId: this.categoryId
                    }).then(
                        (response) => {
                            this.result = response.data.status;
                        },
                        (error) => {
                            this.result = error.response.data;
                        }
                    );
                }
            }
        },
        created() {
            this.categoryId = this.$route.params.id;
            HTTP.get('/category')
                .then(response => (this.model = response.data));
        }
    }
</script>

<style>
    .error {
        position: relative;
        top: -5px;
        font-size: 12px;
        color: red;
    }
</style>