import React, {useEffect, useState} from "react";
import Chart from "@toast-ui/chart";


const options = {
    chart: { width: 1000, height: 600 },
};


const Graphic = ({graphicSeries}) => {
    const [data, setData] = useState({series: []})
    useEffect(() => {
        setData({series: graphicSeries})
    }, [graphicSeries])
    useEffect(() => {
        const el = document.getElementById('chart');
        while (el.childElementCount)
            el.removeChild(el.firstChild)
        Chart.lineChart({ el, data, options });
    }, [data])
    return <div id="chart">F</div>
}

export default Graphic