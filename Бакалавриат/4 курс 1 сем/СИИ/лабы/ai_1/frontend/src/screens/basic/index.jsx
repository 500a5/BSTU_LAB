import React, {useState} from 'react';
import {Switch, Route, Redirect, useRouteMatch, useHistory, useLocation} from 'react-router-dom';
import {Button, Layout, PageHeader, Typography} from 'antd';
import api from "../../utils/api";
import ExitToAppIcon from '@material-ui/icons/ExitToApp';
import PieChartIcon from '@material-ui/icons/PieChart';
import MainPage from "../../components/basic/mainPage";
const {Header} = Layout;

const Basic = () => {
    const {path} = useRouteMatch();
    const history = useHistory();
    return (
        <Layout>
            <Header style={{width: '100%'}}
            >
                <PageHeader
                    style={{height: '100%'}}
                    title={
                        <Typography style={{color: 'white', fontSize: '1em'}}
                                    onClick={() => history.push('/')}
                        >
                            Лабораторная работа №1 (СИИ)
                        </Typography>
                    }
                />
            </Header>
            <Switch>
                <Route exact path={`${path}`}>
                    <MainPage />
                </Route>
                <Route exact path={path}>
                    <Redirect to={`${path}`} />
                </Route>
            </Switch>
        </Layout>
    );
};

export default Basic;
