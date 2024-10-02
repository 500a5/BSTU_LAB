import ky from 'ky';
import historyRef from './history';
import {notification} from "antd";

const rawApi = (url, {headers, ...options} = {}) => {
	const host = process.env.REACT_APP_URL || 'http://127.0.0.1:8000'
	return ky(
		`${host}${url}`,
		{
			timeout: 2 * 60 * 1000,
			headers: {
				...headers
			},
			credentials: 'include',
			hooks: {
				afterResponse: [
					(request, options, response) => {
						if (response.status === 401) {
							// notification.error({
							// 	message: 'Сессия истекла, выполните вход повторно',
							// 	description: response.statusText
							// });
							historyRef.history.push('/');
						} else if (response.status >= 400) {
							notification.error({
								message: 'Ошибка выполнения запроса',
								description: response.statusText
							});
						} else if (!response.ok) {
							notification.error({
								message: 'Ошибка выполнения запроса',
								description: 'Нераспознанная ошибка'
							});
						}
					}
				]
			},
			...options
		}
	);
}

export default rawApi;
