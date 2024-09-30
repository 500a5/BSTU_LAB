import React from 'react';
import {useFormikContext} from 'formik';
import {Button, Col, Form as AntdForm, Row} from 'antd';
import {DeleteOutline} from "@material-ui/icons";

const FormItem = ({Component, name, subName, label, disabled=false, ...props}, ref) => {
    const {
        getFieldMeta,
        getFieldProps,
        status,
        isSubmitting,
        getFieldHelpers,
        isValidating
    } = useFormikContext();

    const meta = getFieldMeta(name);
    let {onBlur, value: values} = getFieldProps(name);
    if (values === null)
        values = []
    const {setValue} = getFieldHelpers(name);
    const error = meta.touched && meta.error;
    return <AntdForm.Item
        hasFeedback={!!error || isValidating}
        help={error}
        label={label}
        required={props.required}
        validateStatus={isValidating ? 'validating' : error ? 'error' : ''}
    >
        <Row>
            <Button style={{color: 'green', marginBottom: '10px'}}
                    onClick={() => {
                        let newRecord = {id: null, organization_id: null}
                        newRecord[subName] = null
                        setValue([...values, newRecord])
                    }}
            >
                Добавить
            </Button>
        </Row>
        {
            values.map((value, index, array) => {
                return (
                    <Row key={index}>
                        <Col span={20}>
                            <Component
                                onBlur={onBlur}
                                onChange={(e) => {
                                    let record = {...array[index]}
                                    record[subName] = e.target.value
                                    setValue([
                                        ...array.slice(0, index),
                                        record,
                                        ...array.slice(index+1)
                                    ])

                                }}
                                value={value[subName]}
                                disabled={isSubmitting || (status && status.isLoading) || disabled}
                                ref={ref}
                                {...props}
                            />
                        </Col>
                        <Col>
                            <Button onClick={() => {
                                setValue([
                                    ...array.slice(0, index),
                                    ...array.slice(index+1)
                                ])
                            }}>
                                <DeleteOutline style={{color: 'red'}}/>
                            </Button>
                        </Col>
                    </Row>
                )
            })
        }
    </AntdForm.Item>
};

export default React.forwardRef(FormItem);
