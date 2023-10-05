import Vue from 'vue'
import VueRouter from 'vue-router'
import Home from '../views/Home.vue'
import catalog from "@/components/Footer";
import Authorization from "@/views/Authorization";
import Registration from "@/views/Registration";

Vue.use(VueRouter)

const routes = [
  {
    path: '/',
    name: 'Home',
    component: Home
  },
  {
    path: '/authorization',
    name: 'Authorization',
    component: Authorization
  },
  {
    path: '/Registration',
    name: 'Registration',
    component: Registration
  },
]

const router = new VueRouter({
  mode: 'history',
  base: process.env.BASE_URL,
  routes
})

export default router
