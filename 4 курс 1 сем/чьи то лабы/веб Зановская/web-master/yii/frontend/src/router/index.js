import Vue from 'vue'
import VueRouter from 'vue-router'
import Home from '../views/Home.vue'

Vue.use(VueRouter)

const routes = [
  {
    path: '/',
    name: 'home',
    component: Home
  },
  {
    path: '/about',
    name: 'about',
    // route level code-splitting
    // this generates a separate chunk (about.[hash].js) for this route
    // which is lazy-loaded when the route is visited.
    component: () => import(/* webpackChunkName: "about" */ '../views/About.vue')
  },
  {
    path: '/news/:id',
    name: 'article',
    component: () => import('../views/Article.vue')
  },
  {
    path: '/cart/:id',
    name: 'cart',
    component: () => import('../views/Record.vue')
  },
  {
    path: '/tours',
    name: 'tours',
    component: () => import('../views/Tours.vue')
  },
  {
    path: '/tours/:id',
    name: 'description',
    component: () => import('../views/Description.vue')
  },
]

const router = new VueRouter({
  routes
})

export default router
