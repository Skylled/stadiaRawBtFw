// 600ff586  FUN_600ff586  size=140 bytes
// --- callers ---
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   60095c34 FUN_60095c34
//   60095b2c FUN_60095b2c


void FUN_600ff586(undefined1 param_1,undefined4 param_2,undefined2 param_3,char param_4,
                 undefined2 param_5,char param_6)

{
  undefined1 local_24;
  undefined1 auStack_23 [7];
  undefined2 local_1c;
  undefined2 local_1a;
  char local_18;
  int local_10;
  undefined1 local_9;
  
  if (param_4 == '\0') {
    local_9 = 0xf;
  }
  else {
    local_9 = 0xe;
  }
  local_10 = FUN_60095b2c(param_1);
  if ((local_10 != 0) && (*(int *)(local_10 + 0x18) != 0)) {
    if (param_6 == '\x01') {
      FUN_60095c34(0x1e,0xff,param_2);
    }
    local_1a = param_5;
    local_18 = param_6;
    local_24 = param_1;
    local_1c = param_3;
    thunk_EXT_FUN_0000b572(auStack_23,param_2,6);
    (**(code **)(local_10 + 0x18))(local_9,&local_24);
  }
  return;
}


