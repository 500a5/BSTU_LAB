import React from 'react';

class ErrorBoundary extends React.Component {
	constructor(props) {
		super(props);

		this.state = {hasError: false};
	}

	static getDerivedStateFromError(error) {
		console.dir(error);

		return {hasError: true};
	}

	componentDidCatch(error, errorInfo) {
		console.dir(errorInfo);
	}

	render() {
		if (this.state.hasError) {
			return (
				<div className="error-boundary">
					<p>При отрисовке страницы произошла ошибка.</p>
					<p>Пожалуйста, перезагрузите страницу или <a href="/">перейдите на главную</a>.</p>
					<p>Если это не помогло, попробуйте удалить данные сайта в настройках браузера</p>
				</div>
			);
		}

		return this.props.children;
	}
}

export default ErrorBoundary;
