import rawApi from './rawApi';

const api = (url, {headers, ...options} = {}) =>
	rawApi(url, {headers, ...options}).json();

export default api;
