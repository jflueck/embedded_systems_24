diag_stage = sldiagviewer.createStage('Find S32k COM port', 'ModelName', gcs);

%% find S32k dev board
dev_name = 'OpenSDA - CDC Serial Port (http://www.pemicro.com/opensda)';

port_name = get_port_name(dev_name);

if (isempty(port_name))
    sldiagviewer.reportError('could not find S32k dev board');
    clear dev_name res ind diag_stage;
    return;
end
sldiagviewer.reportInfo(['S32k dev board found at: ' port_name]);

%% update serial I/O block parameters
serial_blocks = find_system('ReferenceBlock', 'instrumentlib/Serial Configuration');
serial_blocks = [serial_blocks; find_system('ReferenceBlock', 'instrumentlib/Serial Receive')];
serial_blocks = [serial_blocks; find_system('ReferenceBlock', 'instrumentlib/Serial Send')];

for block_index=1:length(serial_blocks)
    set_param(serial_blocks{block_index},'ComPort',port_name,'ObjConstructor',['serial(''' port_name ''');']);
end

clear dev_name res ind port_name serial_blocks block_index diag_stage;