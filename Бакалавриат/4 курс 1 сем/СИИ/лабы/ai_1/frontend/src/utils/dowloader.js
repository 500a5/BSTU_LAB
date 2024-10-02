const downloader = (response, name = 'Файл') => {
	response.blob().then(blob => {
		downloaderBlob(blob, name)
	})
}

const downloaderBlob = (blob, name) => {
	let url = window.URL.createObjectURL(blob);
	let a = document.createElement('a');
	a.href = url;
	a.download = name;
	a.click();
}

export {downloader, downloaderBlob}
