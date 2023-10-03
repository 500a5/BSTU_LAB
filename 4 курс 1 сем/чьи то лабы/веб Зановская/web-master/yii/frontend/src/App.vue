<template>

  <div id="app">

    <header>

      <div class="card text-white bg-dark mb-3">

        <div class="card-body col-6">
          <h2 class="featurette-heading">
            Турагенство ИдуБегуЕду
          </h2>
          <p class="lead">
            Найдем тур в любую часть света.
          </p>
        </div>
      </div>
    </header>
    <main>
      <router-view/>
    </main>

  </div>
</template>

<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
}

#nav {
  padding: 30px;
}

#nav a {
  font-weight: bold;
  color: #2c3e50;
}

#nav a.router-link-exact-active {
  color: #42b983;
}
</style>
