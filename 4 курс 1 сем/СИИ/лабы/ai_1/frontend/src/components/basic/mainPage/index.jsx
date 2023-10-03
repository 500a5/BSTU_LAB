import React, {useEffect, useState} from "react";
import api from "../../../utils/api";
import Loader from "react-loader-spinner";
import {Row, Col, Layout, Tabs, Spin, Typography, Button, Grid} from 'antd'
import "react-loader-spinner/dist/loader/css/react-spinner-loader.css";
import InputField from "./input";
import ChessTable from "../table";
import Graphic from "../Graphic";

const { Header, Content } = Layout;
const { TabPane } = Tabs;


const MainPage = () => {
    const [initT, setInitT] = useState(0);
    const [finalT, setFinalT] = useState(0);
    const [alpha, setAlpha] = useState(0);
    const [step, setStep] = useState(0);
    const [count, setCount] = useState(0);

    const [load, setLoad] = useState(false);
    const [first, setFirst] = useState(true);

    const [codedSolution, setCodedSolution] = useState([])
    const [graphicSeries, setGraphicSeries] = useState([])

    return <div>
        <Row>
            <Col span={18} push={6}>
                <Layout>
                    <Header style={{backgroundColor: 'white'}}>Результаты расчётов</Header>
                    <Content>
                        {
                            load
                                ?
                                <Spin size='large'/>
                                :
                                first
                                    ?
                                    <Typography>
                                        Для получения результатов введите начальные параметры
                                    </Typography>
                                    :
                                    <Tabs defaultActiveKey="1" onChange={() => {}}>
                                        <TabPane tab="Игровое поле" key="1">
                                            <ChessTable codedSolution={codedSolution}/>
                                        </TabPane>
                                        <TabPane tab="Графики" key="2">
                                            <Graphic graphicSeries={graphicSeries}/>
                                        </TabPane>
                                    </Tabs>
                        }
                    </Content>
                </Layout>
            </Col>
            <Col span={6} pull={18}>
                <Layout>
                    <Header style={{backgroundColor: 'white'}}>Введите параметры для расчёта</Header>
                    <Content>
                        <Col style={{margin: '40px'}}>
                            <InputField label='Начальная температура'
                                        onChange={(value) => {setInitT(value)}}
                                        value={initT}
                            />
                            <InputField label='Конечная температура'
                                        onChange={(value) => {setFinalT(value)}}
                                        value={finalT}
                            />
                            <InputField label='Альфа'
                                        onChange={(value) => {setAlpha(value)}}
                                        value={alpha}
                            />
                            <InputField label='Шагов при пост. темп.'
                                        onChange={(value) => {setStep(value)}}
                                        value={step}
                            />
                            <InputField label='Количество ферзей'
                                        onChange={(value) => {setCount(value)}}
                                        value={count}
                            />
                            <Button type='primary' onClick={() => {
                                setLoad(true)
                                api(
                                    '/solution',
                                    {method: 'POST', json: {
                                        init_t: initT,
                                        final_t: finalT,
                                        alpha: alpha,
                                        step: step,
                                        count: count
                                    }}
                                ).then(({solution, graphics}) => {
                                    setCodedSolution(solution)
                                    setGraphicSeries(graphics)
                                    setFirst(false)
                                }).catch(
                                    () => setFirst(true)
                                ).finally(() => {
                                    setLoad(false)
                                })
                            }}>
                                Произвести расчёты
                            </Button>
                        </Col>
                    </Content>
                </Layout>
            </Col>
        </Row>
    </div>
}


export default MainPage