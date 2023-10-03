<template>
    <section class="cart">
        <p>
            Сумма заказа: 1 300 рублей.
        </p>

        <h4 v-if="result === 'success'">Вы успешно сделал заказ на 1300 рублей.</h4>

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
            <div class="form-group">
                <button class="btn btn-primary">Заказать</button>
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
        name: "Cart",
        data() {
            return {
                name: '',
                email: '',
                phone: '',
                result: '',
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
                    HTTP.post('/order/cart', {
                        name: this.name,
                        email: this.email,
                        phone: this.phone
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