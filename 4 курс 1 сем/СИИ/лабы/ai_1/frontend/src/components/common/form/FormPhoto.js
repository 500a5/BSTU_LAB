import React from 'react';
import {Button, Modal, notification, Typography} from 'antd';
import 'antd/dist/antd.css';
import { Upload } from 'antd';
import {DownloadOutlined, PlusOutlined} from '@ant-design/icons';
import rawApi from '../../../utils/rawApi';
import api from '../../../utils/api';
import {downloader} from '../../../utils/dowloader';


function getBase64(file) {
	return new Promise((resolve, reject) => {
		const reader = new FileReader();
		reader.readAsDataURL(file);
		reader.onload = () => resolve(reader.result);
		reader.onerror = error => reject(error);
	});
}


class PicturesWall extends React.Component {
	state = {
		previewVisible: false,
		previewImage: '',
		previewTitle: '',
		fileList: this.props.fileList,
		previewFileId: null
	};

	componentDidMount() {
		let fileList = [];
		if (this.props.editId != null) {
			api(this.props.urlForSave, {method: 'GET'}).then(
				(files) => {
					fileList = files.map((item) => {
						return {
							uid: item.id,
							status: 'done',
							url: item.url
						}
					})
					this.setState({fileList})
				}
			)
		}
	}

	handleCancel = () => this.setState({ previewVisible: false });

	handlePreview = async file => {
		if (!file.url && !file.preview) {
			file.preview = await getBase64(file.originFileObj);
		}

		this.setState({
			previewImage: file.url || file.preview,
			previewVisible: true,
			previewTitle: file.name || file.url.substring(file.url.lastIndexOf('/') + 1),
			previewFileId: file.uid
		});
	};

	handleRemove = ({uid}) => {
		const data = new FormData()
		data.append('file_id', uid)
		rawApi(this.props.urlForSave, {
			method: 'DELETE', body: data
		})
	}

	handleChange = ({ fileList }) => {
		this.setState({ fileList });
	}

	handleDownload = () => {
		rawApi(this.props.urlForSave + 'download', {
			method: 'POST'
		}).then(response => {
			downloader(response)
		})
	}

	customRequest = ({file, method}) => {
		if (this.props.editId != null) {
			const data = new FormData()
			data.append('file', file)
			api(this.props.urlForSave, {
				method: method, body: data
			}).then(() => this.componentDidMount() ).catch();
		} else {
			notification.error({
				message: 'Нельзя добавлять фото, пока запись не сохранена',
				description: 'Сохраните запись'
			});
			this.componentDidMount();
		}
		return {
			abort(file) {console.log('upload progress is aborted.');},
		};
	}

	render() {
		const { previewVisible, previewImage, fileList, previewTitle } = this.state;
		const uploadButton = (
			<div>
				<PlusOutlined />
				<div style={{ marginTop: 8 }}>Загрузить</div>
			</div>
		);
		let upload = (
			<Upload
				customRequest={this.customRequest}
				listType="picture-card"
				fileList={fileList}
				onPreview={this.handlePreview}
				onChange={this.handleChange}
				// onRemove={this.handleRemove}
			>
				{fileList.length >= this.props.maxLength ? null : uploadButton}
			</Upload>
		)
		const onlySee = this.props.onlySee;
		if (onlySee)
			upload = (
				<Upload
					customRequest={this.customRequest}
					listType="picture-card"
					fileList={fileList}
					onPreview={this.handlePreview}
					disabled
				/>
			)
		return (
			<div>
				{upload}
				<Modal
					visible={previewVisible}
					footer={
						<Button type="primary"
								icon={<DownloadOutlined />}
								onClick={this.handleDownload}
						>
							Скачать файл
						</Button>
					}
					onCancel={this.handleCancel}
				>
					<img alt="Файл недоступен к просмотру здесь" style={{ width: '100%' }} src={previewImage} />
				</Modal>
			</div>
		);
	}
}

const FormPhoto = (
	{
		urlForSave, fileList,
		editId, maxLength,
		isPDF = false, onlySee = false
	}) => {
	return (
		<PicturesWall
			urlForSave={urlForSave}
			fileList={fileList}
			editId={editId}
			maxLength={maxLength}
			isPDF={isPDF}
			onlySee={onlySee}
		/>
	);
};

export default FormPhoto;
