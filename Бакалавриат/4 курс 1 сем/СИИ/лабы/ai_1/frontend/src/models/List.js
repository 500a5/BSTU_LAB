import * as mobx from 'mobx';
import _ from 'lodash';

class List
{
	constructor(collection)
	{
		this.collection = collection;

		mobx.makeObservable(
			this,
			{
				data: mobx.observable,
				loading: mobx.observable,
				fetch: mobx.flow,
				reset: mobx.action
			}
		);
	}

	data = null;

	time = null;

	filters = null;

	loading = false;

	* fetch(filters) {
		if (this.time >= this.collection.mtime && _.isEqual(this.filters, filters))
			return;

		try
		{
			this.loading = true;
			this.data = yield this.collection.get(filters);
			this.time = Date.now();
			this.filters = filters;
		}
		finally
		{
			this.loading = false;
		}
	}

	reset()
	{
		this.data = null;
		this.time = null;
		this.filters = null;
	}
}

export default List;
