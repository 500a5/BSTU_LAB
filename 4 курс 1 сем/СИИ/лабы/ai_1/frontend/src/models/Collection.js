import * as mobx from 'mobx';
import * as antd from 'antd';
import api from '../utils/api';

class Collection
{
	constructor(url)
	{
		this.url = url;
		this.touch();

		mobx.makeObservable(
			this,
			{
				mtime: mobx.observable,
				touch: mobx.action
			}
		);
	}

	mtime = null;

	get(filters) {
		return this.request({searchParams: filters});
	}

	getOne(id) {
		return this.request({}, id);
	}

	async create(data) {
		const response = await this.request({method: 'POST', json: data});
		antd.notification.success({message: 'Сущность успешно создана'});
		this.touch();
		return response
	}

	async update(id, data) {
		await this.request({method: 'PUT', json: data}, id);
		antd.notification.success({message: 'Сущность успешно изменена'});
		this.touch();
	}

	async delete(id)
	{
		await this.request({method: 'DELETE'}, id);

		antd.notification.success({message: 'Сущность успешно удалена'});
		this.touch();
	}

	request(options = {}, id = null)
	{
		return api(
			id === null ? `${this.url}/` : `${this.url}/${id}`,
			options
		);
	}

	touch()
	{
		this.mtime = Date.now();
	}
}

export default Collection;
