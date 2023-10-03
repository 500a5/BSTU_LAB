import {Form as AntdForm, InputNumber} from "antd";
import React from "react";

const InputField = ({label, onChange, value, disabled, ...props}) => {
    return <AntdForm.Item
        label={label}
        required={true}
    >
        <InputNumber
            onChange={onChange}
            value={value}
            disabled={disabled}
            {...props}
        />
    </AntdForm.Item>
}


export default InputField