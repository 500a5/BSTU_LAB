const {createProxyMiddleware} = require('http-proxy-middleware');

module.exports = function (app) {
	app.use(
		'/api',
		createProxyMiddleware({
			target: 'http://78.154.244.218:84',
			pathRewrite: {
				'/api/': '/'
			},
			changeOrigin: true
		})
	);
};
