function TraceInfoFlag() {
    this.traceFlag = new Array();
    this.traceFlag["main.c:47c48"]=1;
    this.traceFlag["main.c:47c54"]=1;
    this.traceFlag["main.c:47c73"]=1;
    this.traceFlag["main.c:48c47"]=1;
    this.traceFlag["main.c:48c55"]=1;
    this.traceFlag["main.c:49c9"]=1;
}
top.TraceInfoFlag.instance = new TraceInfoFlag();
function TraceInfoLineFlag() {
    this.lineTraceFlag = new Array();
    this.lineTraceFlag["main.c:47"]=1;
    this.lineTraceFlag["main.c:48"]=1;
    this.lineTraceFlag["main.c:49"]=1;
    this.lineTraceFlag["main.h:40"]=1;
    this.lineTraceFlag["main.h:45"]=1;
}
top.TraceInfoLineFlag.instance = new TraceInfoLineFlag();
