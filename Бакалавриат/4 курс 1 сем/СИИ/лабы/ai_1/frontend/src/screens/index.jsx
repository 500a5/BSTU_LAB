import React from 'react';
import {BrowserRouter as Router, Switch, Route, Redirect} from 'react-router-dom';
import Login from './Login';
import Basic from './basic'
import HistoryThief from '../components/utils/HistoryThief';

const Screens = () => (
	<Router>
		<HistoryThief />
		<Switch>
			<Route path="/login">
				<Login />
			</Route>
			<Route path="/">
				<Basic />
			</Route>
			<Route exact path="/">
				<Redirect to="/" />
			</Route>
		</Switch>
	</Router>
);

export default Screens;
