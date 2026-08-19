// 600db3ea  FUN_600db3ea  size=30 bytes
// --- callers ---
//   60078340 firmware_image_upload__60078340
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600db3ea(undefined1 *param_1,undefined1 *param_2,undefined1 *param_3)

{
  if ((int)param_3 - (int)param_2 == 1) {
    *param_1 = *param_2;
  }
  else if (param_3 != param_2) {
    thunk_EXT_FUN_0000b572();
    return;
  }
  return;
}


