function [port_name] = get_port_name(device_name)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
    [~, devices_json] = system('powershell "Get-CimInstance -ClassName Win32_serialport | select Description, DeviceID | ConvertTo-JSON"');
    devices = jsondecode(devices_json);

    port_name = '';
    for i = 1:numel(devices)
        device = devices(i);
        if contains(device.Description, device_name)
            port_name = device.DeviceID;
            return
        end
    end
end

