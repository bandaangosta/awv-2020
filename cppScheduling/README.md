Test Change
## Scheduler API

* [ ] a start  # -> console <- Human Operator => Exported (see ICD/idl/Scheduler.idl)
* [ ] b stop
* [ ] 1 getProposalStatus  # -> db
* [ ] 2 setProposalStatus
* [ ] 3 cameraOn  # -> instruments (see ICD/idl/Instrument.idl)
* [ ] 5 cameraOff 
* [ ] 4 observe  # -> telescope (see ICD/idl/Telescope.idl)

## Vcode Notes

* Shortcut:
  * Ctrl-P -> commnand : Jump to a file press ctrp-P and copy the path (and press Enter)
  * Shift+Alt -> Column selection
  
* Install plugins:
  * Idl highligthing
  * Cpp plugin from microsoft (has a linter)

## Usefull links:

* BACI Programming a device: https://confluence.alma.cl/display/ICTACS/BACI+Device+Server+Programming+Tutorial
* C++ Hand on: https://confluence.alma.cl/pages/viewpage.action?pageId=54005360
* API design:
  * For ALMA: https://confluence.alma.cl/display/ICTACS/ACS+Workshop+-+Project
  * For Workshop: ./ICD/idl/Scheduler.idl