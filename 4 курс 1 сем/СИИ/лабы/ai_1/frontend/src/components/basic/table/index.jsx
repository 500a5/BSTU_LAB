import React from "react";
import './table.css'


const ChessTable = ({codedSolution}) => {
    const indexArr = codedSolution.map((_, index) => index + 1)


    return (
        <table className={"ExtendSolution"}>
            <tr>
                <th className={"ExtendCell"}/>
                {indexArr.map((index) => <th className={"ExtendCell"}>{index}</th>)}
            </tr>
            {indexArr.map((indexValue, indexRow) => {
                return (
                    <tr>
                        <th className={"ExtendCell"}>{indexValue}</th>
                        {indexArr.map((_, indexCollumn) =>
                            <th className={"ExtendCell"}>
                                {
                                    codedSolution[indexCollumn] === indexRow
                                        ? 'X'
                                        : ''
                                }
                            </th>)}
                    </tr>
                )
            })}
        </table>
    )
}


export default ChessTable